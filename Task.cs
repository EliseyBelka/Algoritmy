//1. Написать функции, которые считывают матрицу смежности из файла и выводят ее на экран.
//2. Написать рекурсивную функцию обхода графа в глубину.
//3. Написать функцию обхода графа в ширину.
//   АВТОР исполения БелкановАлексей
using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
class Const
{
    public const double CoplitedTask=3;
}
namespace CLesson7_CSh_
{
    class Task
    {
        #region Формирование меню
        private static void printMenu()
        {
            int answer = 0;
            do
            {
                Console.WriteLine("Select task number:\n");
                Console.WriteLine("0. ExiT The MenU\n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n1.Read the adjacency matrix;\n2.Deep recursion;\n3.Recursion in width;\n");
                answer = int.Parse(Console.ReadLine());
                Console.Clear();
            } while (answer < 0 || answer > Const.CoplitedTask);
            switch (answer)
            {
                case 0:
                    return;
                case 1:
                    task_1();
                    break;
                case 2:
                    task_2();
                    break;
                case 3:
                    task_3();
                    break;
                default:
                    break;
            }
            Console.WriteLine("\n-=-=-=-=-= Press any key =-=-=-=-=-\n");
            Console.ReadKey();
            Console.Clear();
            printMenu();
        }
        #endregion
        #region Тела программ Task1-3
        private static void task_1()
        {
            string str = "Matrix.txt";
            if (System.IO.File.Exists(str))
            {
                var tuple = TransListMas(str);
                int[,] MasMat = new int[tuple.Item1, tuple.Item1];
                MasMat = tuple.Item2;
                for (int i = 0; i < tuple.Item1; i++)
                {
                    for (int j = 0; j < tuple.Item1; j++)
                        Console.Write(MasMat[i, j]);
                    Console.WriteLine();
                }
            }
            else
            {
                Console.WriteLine("File not exist");
            }
        }
        private static void task_2()
        {
            string str = "Matrix.txt";
            int n;

            if (System.IO.File.Exists(str))
            {
                var tuple = TransListMas(str);
                n = tuple.Item1;
                int[] YetSee = new int[n];
                int[,] MasMat = new int[n, n];
                MasMat = tuple.Item2;
                Console.WriteLine(0);
                for (int i = 0; i < n; i++) //перебераем все верщины
                    if (YetSee[i] == 0)
                        DFS(i, YetSee, MasMat);
            }
            else
            {
                Console.WriteLine("File not exist");
            }
        }
        private static void task_3()
        {
            string str = "MatrixXx.txt";
            int n, i = 0;
            int startNode;
            if (System.IO.File.Exists(str))
            {
                var tuple = TransListMas(str);
                n = tuple.Item1;
                int[] YetSee = new int[n];
                int[] Stack = new int[(int)Math.Pow(2, (double)n - 1)];
                int[,] MasMat = new int[n, n];
                MasMat = tuple.Item2;
                Console.WriteLine($"Which node to start with?[0..{n-1}]");
                startNode = int.Parse(Console.ReadLine()); //стартовый узел
                                                           //  Stack[i] = startNode; //отвечает за очередь узлов на проверку
                YetSee[startNode] = 2; // пометка что узел уже проверялся
                while (i >= 0)
                {
                    for (int j = 0; j < n; j++)
                    {
                        if (MasMat[startNode, j] == 1 & YetSee[j] == 0)
                        {
                            Stack[i] = j;
                            i++;
                            YetSee[j] = 2;
                            Console.Write($"{j,4}");
                        }
                    }
                    if (i - 1 < 0) break;
                    startNode = Stack[i - 1];
                    Stack[i] = 0;
                    i--;
                }
            }
            else
            {
                Console.WriteLine("File not exist");
            }
        }
        #endregion
        #region Task1 Формирование на основании файла с Таблицей Смежности двумерного массива - ТС
        /// <summary>
        /// Считывание файла построчно возврадает List<string>
        /// </summary>
        /// <param name="FileName">Располежение и имя файла</param>
        /// <returns></returns>
        static List<string> ReadFile(string FileName)
        {
            List<string> Lst = new List<string>();
            try
            {
                using (StreamReader sr = new StreamReader(FileName))
                {
                    string line;
                    while ((line = sr.ReadLine()) != null)
                    {
                        Lst.Add(line);
                    }
                }
            }
            catch (Exception e)
            {
                Console.WriteLine("The file not exist:");
                Console.WriteLine(e.Message);
            }
            return Lst;
        }
        /// <summary>
        /// Преобразование листа строк в отдельные символы. Возврашает List<int> символов в одну строку 
        /// </summary>
        /// <param name="FileName">Метсоположение и название файла</param>
        /// <returns></returns>
        static List<int> PrintMatrix(string FileName)
        {
            List<string> temp = new List<string>();
            temp = ReadFile(FileName);
            List<int> LMatrix = new List<int>();
            foreach (string s in temp)
            {
                string[] split = s.Split(new[] { ' ' });
                foreach (string symbol in split)
                    LMatrix.Add((int.Parse(symbol)));
            }
            return LMatrix;
        }
        /// <summary>
        /// Преобразует List символов в двумерный массив передает обр размер массива int и массив int[,]
        /// </summary>
        /// <param name="FileName">Путь к файлу</param>
        /// <returns></returns>
        static Tuple<int, int[,]> TransListMas(string FileName)
        {
            int col = 0, row = 0;
            List<int> LMatrix = new List<int>();
            LMatrix = PrintMatrix(FileName);
            int n = LMatrix.ElementAt(0);
            int[,] MasMat = new int[n, n];
            LMatrix.RemoveAt(0);
            foreach (int i in LMatrix)
            {
                MasMat[row, col] = i;
                col++;
                if (col == n)
                {
                    col = 0;
                    row++;
                }
            }
            return Tuple.Create(n, MasMat);
        }
        #endregion
        #region Task2 Обход графа в глубину
        /// <summary>
        /// Обход графа в глубину
        /// </summary>
        /// <param name="k">Вершина с которой начинается обход</param>
        /// <param name="YetSee">Массив храняший информацию о пройденных вершинах</param>
        /// <param name="MasMat">Таблица смежности</param>
        static void DFS(int k, int[] YetSee, int[,] MasMat)
        {
            YetSee[k] = 2; // отмечаемся в текущей верщине
            for (int l = 0; l < YetSee.Length; l++) //пробегаем по всем вершинам и проверяем связь
            {
                if ((MasMat[k, l] == 1) & (YetSee[l] == 0)) //если элемент имеет связь 1 и мы в вршине небыли
                {
                    Console.Write($"{l,4}");
                    DFS(l, YetSee, MasMat);
                }
            }
        }
        #endregion
        static void Main()
        {
            printMenu();
        }
    }
}
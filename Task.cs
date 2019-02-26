using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lesson8_CSh_
{
    class Task
    {

        static int numbers = 0;
        #region Формирование меню
        private static void printMenu()
        {
            int answer = 0, kol = 0;
            do
            {
                Console.WriteLine("Select number of values:\n");
                Console.WriteLine("0. ExiT The MenU\n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n1.100;\n2.10000;\n3.1000000;\n");
                kol = int.Parse(Console.ReadLine());
                Console.Clear();
            } while (kol < 0 || kol > 3);
            switch (kol)
            {
               case 1:
                    numbers=100;
                    break;
                case 2:
                    numbers = 10000;
                    break;
                case 3:
                    numbers = 1000000;
                    break;
                default:
                    break;
            }
            do
            {
                Console.WriteLine("Select task number:\n");
                Console.WriteLine("0. ExiT The MenU\n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n1.Сounting;\n2.Fast;\n3.Merger;\n");
                answer = int.Parse(Console.ReadLine());
                Console.Clear();
            } while (answer < 0 || answer > 3);
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
            if (numbers!=0)
            {
                #region Объявление переменных
                Random rnd = new Random();          //rnd - лок~ отвечает за генерирование значений псевдослучайнм образом.
                int j = 0;                          //индекс
                int value = numbers / 2;              //пусть массив заполнится чилслами принимающие значения от 0 до значения количества цифр/2
                int[] MassNum = new int[numbers];   // "Подоваемый" массив - numbers(количество элементов массива для сортировки)
                int[] MasSupp = new int[value];
                #endregion
                #region Подготовительный этап заполнение массивов
                Console.WriteLine("The array is filled:");  //для красоты
                for (int i = 0; i < numbers; i++)
                {
                    MassNum[i] = rnd.Next(0, value);        //массив заполняется случайными числами с диапазона(0..value-1)
                    Console.Write($"{MassNum[i]} ");
                }
                for (int i = 0; i < value; i++)
                {
                    MasSupp[i] = 0;                         //зануление массиива, в С# можно опустить в С нужен.
                }
                Console.WriteLine("Press any key...");      //для красоты
                Console.ReadKey();                          // пауза перед сортировкой
                #endregion
                #region Сортировка
                DateTime start = DateTime.Now;      //старт секундомер
                for (int i = 0; i < numbers; i++)
                {
                    MasSupp[MassNum[i]]++;
                }
                for (int i = 0; i < value; i++)
                {
                    for (int k = 0; k < MasSupp[i]; k++)
                    {
                        MassNum[j] = i;
                        j++;
                    }
                }
                DateTime stop = DateTime.Now;       //стоп секундомер
                #endregion
                #region Вывод результата и времени
                Console.WriteLine("\nSorted array:");                               //для красоты
                for (int i = 0; i < numbers; i++) Console.Write($"{MassNum[i]} ");  //вывод массива отсортированного
                Console.WriteLine($"\nOperating time:{stop - start}");              //Расчет времени между началом и концом
                #endregion
            }
            else Console.WriteLine("Array should not be empty");
        }
        private static void task_2()
        {
            if (numbers != 0)
            {
                #region Объявление переменных
                Random rnd = new Random();
                int value = numbers / 2;
                int[] MassNum = new int[numbers];
                #endregion
                #region Подготовительный этап заполнение массивов
                Console.WriteLine("The array is filled:");  //для красоты
                for (int i = 0; i < numbers; i++)
                {
                    MassNum[i] = rnd.Next(0, value);        //массив заполняется случайными числами с диапазона(0..value-1)
                    Console.Write($"{MassNum[i]} ");
                }
                Console.WriteLine("Press any key...");      //для красоты
                Console.ReadKey();
                #endregion
                DateTime start = DateTime.Now;
                quicksort(MassNum,MassNum[0],MassNum[value-1]);
                DateTime stop = DateTime.Now;
                #region Вывод результата и времени
                Console.WriteLine("\nSorted array:");                               //для красоты
                for (int i = 0; i < numbers; i++) Console.Write($"{MassNum[i]} ");  //вывод массива отсортированного
                Console.WriteLine($"\nOperating time:{stop - start}");              //Расчет времени между началом и концом
                #endregion
            }
            else Console.WriteLine("Array should not be empty");
        }
        private static void task_3()
        {
            if (numbers != 0)
            {
            #region Объявление переменных
            Random rnd = new Random();
            int value = numbers / 2;
            int[] MassNum = new int[numbers];
            #endregion
            #region Подготовительный этап заполнение массивов
            Console.WriteLine("The array is filled:");  //для красоты
            for (int i = 0; i < numbers; i++)
            {
                MassNum[i] = rnd.Next(0, value);        //массив заполняется случайными числами с диапазона(0..value-1)
                Console.Write($"{MassNum[i]} ");
            }
            Console.WriteLine("Press any key...");      //для красоты
            Console.ReadKey();
            #endregion
            DateTime start = DateTime.Now;
            MassNum = MergeSort(MassNum);
            DateTime stop = DateTime.Now;
            #region Вывод результата и времени
            Console.WriteLine("\nSorted array:");                               //для красоты
            for (int i = 0; i < numbers; i++) Console.Write($"{MassNum[i]} ");  //вывод массива отсортированного
            Console.WriteLine($"\nOperating time:{stop - start}");              //Расчет времени между началом и концом
                #endregion
            }
            else Console.WriteLine("Array should not be empty");
        }
        #endregion
        #region Быстрая сортировка
        #region Разделение массива на две половины по опорному элементу
        /// <summary>
        /// Разделение массива перед сортировкой
        /// </summary>
        /// <param name="array">Сортируемый массив</param>
        /// <param name="first">Первый элемент массива</param>
        /// <param name="last">Последний элемент массива</param>
        /// <returns>ОЗначение опорного элемента</returns>
        static int division(int[] array, int first, int last) 
        {
            int temp; //доп переменная для обмена
            int reference = (last-first)/2; // индекс опорного - лучше если массив разделится поровну => опорный в середине
            for (int i = first; i <= last; i++) //пробегаем от первого до последнего
            {
                if (array[i] < array[reference]) //если текушее значение меньше опорного
                {
                    temp = array[reference]; // опорный во временное хранилище
                    array[reference] = array[i]; //в опорный сохраняем текщий
                    array[i] = temp; //в текщий опорный
                    reference += 1; //индекс опорного увеличиваем на 1
                }
            }
            //после прохождения массива меняю местами опорный и последний
            temp = array[reference];
            array[reference] = array[last]; 
            array[last] = temp; 
            return reference;
        }
        #endregion
        #region Сортировка полвинок
        static void quicksort(int[] array, int first, int last)
        {
            if (first >= last)
            {
                return;
            }
            int pivot = division(array, first, last);
            quicksort(array, first, pivot - 1);
            quicksort(array, pivot + 1, last);
        }
        #endregion
        #endregion
        #region Сортировка слиянием
        static int[] MergeSort(int[] massive)
        {
            if (massive.Length == 1)
                return massive;
            int mid_point = massive.Length / 2;
            return Merge(MergeSort(massive.Take(mid_point).ToArray()), MergeSort(massive.Skip(mid_point).ToArray()));
        }
        static int[] Merge(int[] mass1, int[] mass2)
        {
            int a = 0, b = 0;
            int[] merged = new int[mass1.Length + mass2.Length];
            for (int i = 0; i < mass1.Length + mass2.Length; i++)
            {
                if (b < mass2.Length && a < mass1.Length)
                    if (mass1[a] > mass2[b])
                        merged[i] = mass2[b++];
                    else 
                        merged[i] = mass1[a++];
                else
                    if (b < mass2.Length)
                    merged[i] = mass2[b++];
                else
                    merged[i] = mass1[a++];
            }
            return merged;
        }
        #endregion
        static void Main()
        {
            printMenu();
        }
    }
}
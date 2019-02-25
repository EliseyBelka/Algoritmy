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
           
        }
        private static void task_3()
        {
          
        }
        #endregion
       
        static void Main()
        {
            printMenu();
        }
    }
}
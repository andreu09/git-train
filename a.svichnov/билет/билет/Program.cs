using System;
using System.Linq;

namespace билет
{
    class Program
    {
        static void Main()
        {
            Console.Write("Введите номер билета:  ");
            string str = Console.ReadLine();
            char[] ch = new char[str.Length];
            ch = str.ToCharArray();
            int[] ticketNumber = ch.Select(s => int.Parse(s.ToString())).ToArray();
            int middle = ticketNumber.Length / 2;
              if (ch.Length % 2 == 0)
            {
                int leftNumber = 0;
                int rightNumber = 0;

                for (int i = 0; i < ch.Length; i++)
                {
                    if (i < middle)
                    {
                        leftNumber += ticketNumber[i];
                    }

                    else rightNumber += ticketNumber[i];
                }

                if (leftNumber == rightNumber)
                {
                    Console.WriteLine("У вас счастливый билет: {0} = {1}", leftNumber, rightNumber);
                }

                else Console.WriteLine("У вас не счастливый билет: {0} != {1}", leftNumber, rightNumber);
            }

            else Console.WriteLine("Число должно быть четным!");

            Console.Read();

        }
    }
}  


using System;

namespace ConsoleApp2
{
    
        class Program
        {
            static void Main()
            {
                int n = InputN("Введите N","N целое число");
                int[,] values = GetRandomValues(n);

               matrix(values);
               spiral(values);
            }

            private static void matrix(int[,] values)
            {
                const int dm = 0;
                int dl = (int)values.GetLongLength(dm);
                for (int i = 0; i < dl; i++)
                {
                    for (int j = 0; j < dl; j++)
                        Console.Write($"{values[i, j]} ");

                    Console.WriteLine();
                }
            }

            private static void spiral(int[,] values)
            {
                const int dn = 0;
                int dl = (int)values.GetLongLength(dn);

                int squaresCount = dl / 2;

                Console.Write($"{values[squaresCount, squaresCount]} ");
                for (int i = squaresCount - 1; i > -1; i--)
                {
                    for (int j = i + 1; j < dl - i; j++)
                        Console.Write($"{values[j, i]} ");

                    for (int j = i + 1; j < dl - i - 1; j++)
                        Console.Write($"{values[dl - i - 1, j]} ");

                    for (int j = dl - i - 1; j > i; j--)
                        Console.Write($"{values[j, dl - i - 1]} ");

                    for (int j = dl - i - 1; j > i - 1; j--)
                        Console.Write($"{values[i, j]} ");
                }
            }

            private static int InputN(string inputMessage, string errorMessage)
            {
                Console.WriteLine(inputMessage);

                int result;
                while (!int.TryParse(Console.ReadLine(), out result))
                    Console.WriteLine(errorMessage);

                return result;
            }

            private static int[,] GetRandomValues(int n)
            {
               
                Random random = new Random();

                int length = 2 * n - 1;
                int[,] result = new int[length, length];
                for (int i = 0; i < length; i++)
                    for (int j = 0; j < length; j++)
                        result[i, j] = random.Next(10);

                return result;
            }
        }
    }
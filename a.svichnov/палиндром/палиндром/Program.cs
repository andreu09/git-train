using System;

namespace палиндром
{
    class Program
    {
        static void Main(string[] args)
        {
            int i = 0;
            int j = 0;
            Console.WriteLine("Введите строку: ");
            string str = Console.ReadLine();
            char[] newstr = str.ToCharArray();
            char[] newstr1 = new char[str.Length];
            foreach (char value in newstr)
            {

                if (newstr[i] != ' ' || newstr[i] != 10 || newstr[i] != 13)
                {
                    newstr1[j] = newstr[i];
                    j++;

                }
                i++;
            }
            string str3 = new string(newstr1);
            Array.Reverse(newstr1);
            string str2 = new string(newstr1);
            if (str3.Equals(str2))
                Console.WriteLine("true");
            else Console.WriteLine("false");

            Console.ReadLine();
        }


    }
}      
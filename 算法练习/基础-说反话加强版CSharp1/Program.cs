using System;
using System.Collections.Generic;
using System.Collections;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace 基础-说反话加强版CSharp1
{
    class Program
    {
        static void Main(string[] args)
        {
            String str;
            String[] temp;
            str = System.Console.ReadLine();
            temp = str.Split(' ');
            ArrayList words = new ArrayList(temp);


            for (int i = 0; i < words.Count; ++i)
            {
                if (words[i].ToString() == "")
                {
                    words.RemoveAt(i--);

                }
            }
            for (int i = words.Count - 1; i > 0; --i)
            {
                Console.Write("{0} ", words[i]);
            }
            Console.Write("{0}\n", words[0]);
            Console.ReadKey();
        }
    }
}

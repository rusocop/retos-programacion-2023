using System;
public class Trifuerza
{
    public static void Main(string[] args)
    {
        int num = Convert.ToInt32(Console.ReadLine());
        int fila;
        int espacios = 2 * num - 1;
        int filas = 2 * num + 1; // ("+1" porque el for empieza en el 1 en vez de 0)

        for (fila = 1; fila < (filas); fila++)
        {
            for (int n = 0; n < espacios; n++)
            {
                Console.Write(" ");
            }

            espacios--;

            if (fila % 2 == 1) // impar
            {
                for (int impar = 0; impar < ((fila / 2) + 1); impar++)
                {
                    Console.Write("*   ");
                }
                Console.WriteLine();
            }

            else // par
            {
                for (int par = 0; par < (fila / 2); par++)
                {
                    Console.Write("*** ");
                }
                Console.WriteLine();
            }
        }
    }
}
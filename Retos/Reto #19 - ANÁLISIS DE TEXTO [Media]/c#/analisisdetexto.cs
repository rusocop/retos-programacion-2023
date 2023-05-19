/*
 * Crea un programa que analice texto y obtenga:
 * - Número total de palabras.
 * - Longitud media de las palabras.
 * - Número de oraciones del texto (cada vez que aparecen un punto).
 * - Encuentre la palabra más larga.
 *
 * Todo esto utilizando un único bucle.
 */

class Texto
{
    static void Main(string[] args)
    {
        int totalPalabras;
        double mediaLongitud = 0;
        double totalLongitud = 0;
        int totalOraciones = 0;
        string palabraMasLarga = "";
        string palabraAnterior = "";


        string usuarioTexto = "Hola que tal me llamo Pedro. Vivo en un pueblo.";
        usuarioTexto = usuarioTexto.Trim();

        string[] palabras = usuarioTexto.Split(" ");

        totalPalabras = palabras.Length;

        for (int n = 0; n < palabras.Length; n++)
        {

            if (palabras[n].Length > palabraAnterior.Length)
            {
                palabraMasLarga = palabras[n];
            }

            if (palabras[n].Contains("."))
            {
                totalOraciones++;
                totalLongitud--;
            }

            totalLongitud = totalLongitud + palabras[n].Length;

            palabraAnterior = palabras[n];
        }

        mediaLongitud = totalLongitud / totalPalabras;

        Console.WriteLine("Total palabras " + totalPalabras + ", longitud media de palabra: " + mediaLongitud + ", hay " + totalOraciones + " oraciones" + ", y palabra mas larga: " + palabraMasLarga);
    }
}
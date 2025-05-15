#pragma warning disable CA1416
using System;
using System.Drawing;
using System.Drawing.Imaging;
using System.IO;

// Бусыгина Татьяна, ИВТ-22

public static class ImageProcessor
{
    /// <summary>
    /// Применение фильтра
    /// </summary>
    /// <param name="imagePath">Путь к изображению</param>
    /// <param name="outputDir">Папка для сохранения результата</param>
    /// <param name="kernel">Фильтр в виде матрицы 3x3</param>
    public static void ApplyFilter(string imagePath, string outputDir, float[,] kernel)
    {
        try
        {
            // Загружаем изображение из файла
            // using гарантирует автоматическое освобождение памяти
            using Bitmap source = new Bitmap(imagePath);
            // Создаём пустую "канву" с таким же размером, как у исходного, сюда будет записывать измененный пиксели
            Bitmap result = new Bitmap(source.Width, source.Height);

            // Идём по пикселям, границы пропускаем, т.к. надо чтоб было вокруг пикселя 3x3
            for (int y = 1; y < source.Height - 1; y++)
            {
                for (int x = 1; x < source.Width - 1; x++)
                {
                // Перебираем 9 пикселей вокруг текущего(x, y) — 3×3.
                // Берём соответствующий коэффициент из матрицы фильтра
                // Умножаем цветовые компоненты (R, G, B) на коэффициент и суммируем
                    float r = 0, g = 0, b = 0;

                    for (int ky = -1; ky <= 1; ky++)
                    {
                        for (int kx = -1; kx <= 1; kx++)
                        {
                            Color pixel = source.GetPixel(x + kx, y + ky);
                            float k = kernel[ky + 1, kx + 1];
                            r += pixel.R * k;
                            g += pixel.G * k;
                            b += pixel.B * k;
                        }
                    }

                // Создаём цвет с нормализованными значениями(0–255)
                // Ставим полученный цвет в соответствующий пиксель результата.
                    result.SetPixel(x, y, Color.FromArgb(Clamp(r), Clamp(g), Clamp(b)));
                }
            }

            string fileName = Path.GetFileName(imagePath); // Получаем имя файла
            string outputPath = Path.Combine(outputDir, fileName); // Создаем полный путь к выходному изображению
            result.Save(outputPath, ImageFormat.Png); // Сохраняем как png

            Console.WriteLine($"Обработано: {fileName}");
        }
        catch (Exception ex)
        {
            Console.WriteLine($"Ошибка при обработке {Path.GetFileName(imagePath)}: {ex.Message}");
        }
    }

    // Обеспечивает, что цвет не выйдет за пределы допустимого диапазона(0–255)
    // Например, если сумма r получилась -30 станет 0; если 300 станет 255
    private static int Clamp(float value)
    {
        return (int)Math.Max(0, Math.Min(255, value));
    }

    // Фильтры
    public static float[,] EngravingFilter => new float[,]
    {
        { -0.2f, -1f,  -0.2f },
        { -1f,    5f,  -1f   },
        { -0.2f, -1f,  -0.2f }
    };

    public static float[,] BlurFilter => new float[,]
    {
        { 1f/9, 1f/9, 1f/9 },
        { 1f/9, 1f/9, 1f/9 },
        { 1f/9, 1f/9, 1f/9 }
    };
}

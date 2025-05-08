using System;
using System.Collections.Generic;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Drawing;

namespace ProducerAndConsumer
{
    /// <summary>
    /// Класс содержит метод для применения фильтра к изображению
    /// Применяется фильтр преобразования изображения в оттенки серого
    /// </summary>
    class Filter
    {
        /// <summary>
        /// Применяет фильтр оттенков серого к изображению
        /// Каждый пиксель преобразуется путём усреднения его RGB значений
        /// </summary>
        /// <param name="bmp">Изображение, представленное объектом Bitmap</param>
        public static void Apply(Bitmap bmp)
        {
            // Проходим по всем строкам изображения
            for (int y = 0; y < bmp.Height; y++)
            {
                // Проходим по всем пикселям строки
                for (int x = 0; x < bmp.Width; x++)
                {
                    // Получаем оригинальный цвет текущего пикселя
                    Color original = bmp.GetPixel(x, y);
                    // Рассчитываем среднее значение
                    int gray = (original.R + original.G + original.B) / 3;
                    // Создаём новый серый цвет с одинаковыми зачениями RGB
                    Color grayColor = Color.FromArgb(gray, gray, gray);
                    // Заменяем текущий пиксель новым цветом
                    bmp.SetPixel(x, y, grayColor);
                }
            }
        }
    }
}

using System;
using System.Windows.Forms;

namespace Homework1
{
    class Program
    {
        static void Main()
        {
            // Первое сообщение
            MessageBox.Show("Имя: Иван Иванов", "Мое резюме");
            
            // Второе сообщение
            MessageBox.Show("Возраст: 25 лет\nОпыт работы: 2 года", "Мое резюме");
            
            // Третье сообщение
            MessageBox.Show("Навыки: C#, SQL, HTML", "Мое резюме");
            
            // Четвертое сообщение с расчетом среднего
            string message1 = "Имя: Иван Иванов";
            string message2 = "Возраст: 25 лет\nОпыт работы: 2 года";
            string message3 = "Навыки: C#, SQL, HTML";
            
            int totalChars = message1.Length + message2.Length + message3.Length;
            double average = totalChars / 3.0;
            
            MessageBox.Show("Спасибо за внимание!", $"Среднее: {average:F1} символов");
        }
    }
}

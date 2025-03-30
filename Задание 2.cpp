using System;
using System.Windows.Forms;

namespace Homework1
{
    class Program
    {
        static void GuessNumber()
        {
            int min = 1;
            int max = 2000;
            int guess;
            int count = 0;
            
            while (true)
            {
                count++;
                guess = (min + max) / 2;
                
                var result = MessageBox.Show(
                    $"Ваше число {guess}?",
                    "Угадывание числа",
                    MessageBoxButtons.YesNo,
                    MessageBoxIcon.Question);
                
                if (result == DialogResult.Yes)
                {
                    MessageBox.Show(
                        $"Ура! Число угадано за {count} попыток!",
                        "Поздравляем!",
                        MessageBoxButtons.OK,
                        MessageBoxIcon.Information);
                    
                    var playAgain = MessageBox.Show(
                        "Хотите сыграть еще?",
                        "Играем еще?",
                        MessageBoxButtons.YesNo,
                        MessageBoxIcon.Question);
                    
                    if (playAgain == DialogResult.Yes)
                    {
                        GuessNumber(); // Начинаем новую игру
                    }
                    return;
                }
                else
                {
                    result = MessageBox.Show(
                        "Ваше число больше?",
                        "Уточнение",
                        MessageBoxButtons.YesNo,
                        MessageBoxIcon.Question);
                    
                    if (result == DialogResult.Yes)
                    {
                        min = guess + 1;
                    }
                    else
                    {
                        max = guess - 1;
                    }
                }
            }
        }
        
        static void Main()
        {
            GuessNumber();
        }
    }
}

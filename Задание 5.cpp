using System;
using System.Drawing;
using System.Windows.Forms;

namespace Homework1
{
    public class MainForm : Form
    {
        private Label runningStatic;
        private const int RunDistance = 50;
        
        public MainForm()
        {
            this.Text = "Убегающий статик";
            this.ClientSize = new Size(600, 400);
            
            runningStatic = new Label();
            runningStatic.Text = "Убегаю!";
            runningStatic.AutoSize = false;
            runningStatic.Size = new Size(80, 30);
            runningStatic.BackColor = Color.LightGreen;
            runningStatic.TextAlign = ContentAlignment.MiddleCenter;
            
            // Начальная позиция
            MoveStaticToRandomPosition();
            
            this.Controls.Add(runningStatic);
            this.MouseMove += MainForm_MouseMove;
        }
        
        private void MainForm_MouseMove(object sender, MouseEventArgs e)
        {
            // Расстояние от курсора до статика
            double distance = Math.Sqrt(
                Math.Pow(e.X - (runningStatic.Left + runningStatic.Width / 2), 2) +
                Math.Pow(e.Y - (runningStatic.Top + runningStatic.Height / 2), 2));
            
            if (distance < RunDistance)
            {
                MoveStaticAwayFrom(e.Location);
            }
        }
        
        private void MoveStaticAwayFrom(Point mousePos)
        {
            int newX = runningStatic.Left;
            int newY = runningStatic.Top;
            
            // Двигаемся в противоположную сторону от курсора
            if (mousePos.X < runningStatic.Left + runningStatic.Width / 2)
            {
                newX += 20; // Вправо
            }
            else
            {
                newX -= 20; // Влево
            }
            
            if (mousePos.Y < runningStatic.Top + runningStatic.Height / 2)
            {
                newY += 20; // Вниз
            }
            else
            {
                newY -= 20; // Вверх
            }
            
            // Проверяем, чтобы не выйти за границы формы
            newX = Math.Max(0, Math.Min(this.ClientSize.Width - runningStatic.Width, newX));
            newY = Math.Max(0, Math.Min(this.ClientSize.Height - runningStatic.Height, newY));
            
            runningStatic.Location = new Point(newX, newY);
        }
        
        private void MoveStaticToRandomPosition()
        {
            Random rnd = new Random();
            int x = rnd.Next(0, this.ClientSize.Width - runningStatic.Width);
            int y = rnd.Next(0, this.ClientSize.Height - runningStatic.Height);
            runningStatic.Location = new Point(x, y);
        }
    }
    
    class Program
    {
        static void Main()
        {
            Application.Run(new MainForm());
        }
    }
}

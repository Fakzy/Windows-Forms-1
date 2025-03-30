using System;
using System.Windows.Forms;

public class Form1 : Form
{
    TextBox textBox1;
    Button button1;
    Label label1;

    public Form1()
    {
        this.Text = "День недели";
        this.Size = new System.Drawing.Size(300, 200);

        textBox1 = new TextBox();
        textBox1.Location = new System.Drawing.Point(50, 50);
        textBox1.Size = new System.Drawing.Size(200, 20);

        button1 = new Button();
        button1.Text = "Узнать";
        button1.Location = new System.Drawing.Point(50, 80);
        button1.Click += ButtonClick;

        label1 = new Label();
        label1.Location = new System.Drawing.Point(50, 120);
        label1.Size = new System.Drawing.Size(200, 20);

        this.Controls.Add(textBox1);
        this.Controls.Add(button1);
        this.Controls.Add(label1);
    }

    void ButtonClick(object sender, EventArgs e)
    {
        try
        {
            DateTime date = DateTime.Parse(textBox1.Text);
            label1.Text = date.DayOfWeek.ToString();
        }
        catch
        {
            MessageBox.Show("Введите дату правильно!");
        }
    }

    public static void Main()
    {
        Application.Run(new Form1());
    }
}

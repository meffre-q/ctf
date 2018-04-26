using System;
using System.Diagnostics;
using System.Drawing;
using System.Runtime.InteropServices;
using System.Windows.Forms;

[ComVisible(true)]
public class AingeiRai5HahfeiThe2 : Form
{
        private Button validate_button;

        private TextBox text_box;

        private Label label_magic;

        private string encode_text;

        private int[] az5nieghahj0Iekah0ph = new int[22]
        {
                21,
                91,
                20,
                0,
                126,
                0,
                61,
                24,
                2,
                82,
                7,
                17,
                88,
                22,
                18,
                21,
                114,
                117,
                15,
                80,
                59,
                24
        };

        public AingeiRai5HahfeiThe2()
        {
                Jojei5ahyah2yah5laeK();
        }

        public void Aa6bi4uidan4shahSee9(string ain7aek2Thae3Boh7ohh)
        {
                encode_text = ain7aek2Thae3Boh7ohh.Substring(ain7aek2Thae3Boh7ohh.Length - 22);
        }

        public void Joh8achoo1aepahjeiy9()
        {
                Application.Run(this);
        }

        private void Jojei5ahyah2yah5laeK()
        {
                validate_button = new Button();
                text_box = new TextBox();
                label_magic = new Label();
                base.SuspendLayout();
                validate_button.Location = new Point(12, 102);
                validate_button.Name = "btnOk";
                validate_button.Size = new Size(259, 23);
                validate_button.TabIndex = 0;
                validate_button.Text = "Validate";
                validate_button.UseVisualStyleBackColor = true;
                validate_button.Click += validate_func;
                text_box.Location = new Point(12, 39);
                text_box.Name = "magicTxt";
                text_box.Size = new Size(259, 20);
                text_box.TabIndex = 1;
                label_magic.AutoSize = true;
                label_magic.Location = new Point(9, 9);
                label_magic.Name = "magicLbl";
                label_magic.Size = new Size(110, 13);
                label_magic.TabIndex = 2;
                label_magic.Text = "Enter the magic word:";
                base.ClientSize = new Size(284, 138);
                base.Controls.Add(label_magic);
                base.Controls.Add(text_box);
                base.Controls.Add(validate_button);
                base.Name = "SoStealthy";
                base.ResumeLayout(false);
                base.PerformLayout();
        }

        private bool decode_text(string magicWord)
        {
                for (int i = 0; i < encode_text.Length; i++)
                {
                        uint num = (uint)(magicWord[i] ^ encode_text[i]);
                        if (num != az5nieghahj0Iekah0ph[i])
                        {
                                return false;
                        }
                }
                return true;
        }

        private void validate_func(object ahrah0iwoChohs2dai4a, EventArgs ahH5eedeiYohquei8goo)
        {
                if (Debugger.IsAttached)
                {
                        MessageBox.Show("Don't try your dirty tricks on me!");
                }
                else if (text_box.Text.Length == 0)
                {
                        MessageBox.Show("You must fill this field!");
                }
                else if (decode_text(text_box.Text))
                {
                        MessageBox.Show("SUCCESS !\nSubmit NDH{" + text_box.Text + "} to validate.");
                }
                else
                {
                        MessageBox.Show("YOU DIDN'T SAY THE MAGIC WORD !!!");
                }
        }
}

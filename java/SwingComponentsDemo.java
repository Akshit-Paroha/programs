import javax.swing.*;
import java.awt.event.*;

public class SwingComponentsDemo
{
    public static void main(String[] args)
    {
        JFrame f = new JFrame("Swing Components Demo");
        f.setSize(400, 300);
        f.setLayout(null);

        JLabel l = new JLabel("Select your preferences:");
        l.setBounds(50, 20, 200, 30);
        f.add(l);

        JCheckBox c1 = new JCheckBox("Java");
        JCheckBox c2 = new JCheckBox("Python");
        c1.setBounds(50, 60, 100, 30);
        c2.setBounds(150, 60, 100, 30);
        f.add(c1);
        f.add(c2);

        JRadioButton r1 = new JRadioButton("Male");
        JRadioButton r2 = new JRadioButton("Female");
        r1.setBounds(50, 100, 100, 30);
        r2.setBounds(150, 100, 100, 30);
        ButtonGroup bg = new ButtonGroup();
        bg.add(r1);
        bg.add(r2);
        f.add(r1);
        f.add(r2);

        JButton b = new JButton("Submit");
        b.setBounds(100, 150, 100, 30);
        f.add(b);

        b.addActionListener(new ActionListener()
        {
            public void actionPerformed(ActionEvent e)
            {
                String lang = "";
                if (c1.isSelected()) lang += "Java ";
                if (c2.isSelected()) lang += "Python ";
                String gender = r1.isSelected() ? "Male" : (r2.isSelected() ? "Female" : "None");
                JOptionPane.showMessageDialog(f, "Languages: " + lang + "\nGender: " + gender);
            }
        });

        f.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        f.setVisible(true);
    }
}


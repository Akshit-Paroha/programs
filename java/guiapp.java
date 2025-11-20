import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class guiapp
{
    public static void main(String[] args)
    {
        JFrame jf = new JFrame("Registration Form");
        jf.setVisible(true);
        jf.setSize(1600, 900);
        jf.setLayout(new GridLayout(7, 2, 10, 10));
        jf.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        JLabel msg = new JLabel("", SwingConstants.CENTER);
        msg.setFont(new Font("Arial", Font.BOLD, 22));
        msg.setForeground(Color.RED);
        jf.add(msg);
        jf.add(new JLabel(""));

        JLabel FN = new JLabel("First Name");
        jf.add(FN);

        JTextField firstName = new JTextField();
        jf.add(firstName);

        JLabel LN = new JLabel("Last Name");
        jf.add(LN);

        JTextField lastName = new JTextField();
        jf.add(lastName);

        JCheckBox py = new JCheckBox("Python");
        jf.add(py);

        JCheckBox jv = new JCheckBox("Java");
        jf.add(jv);

        JRadioButton M = new JRadioButton("Male");
        jf.add(M);

        JRadioButton F = new JRadioButton("Female");
        jf.add(F);

        ButtonGroup BG = new ButtonGroup();
        BG.add(M);
        BG.add(F);

        JButton S = new JButton("Submit");
        JButton R = new JButton("Reset");
        jf.add(S);
        jf.add(R);

        S.addActionListener(new ActionListener()
        {
            public void actionPerformed(ActionEvent e)
            {
                msg.setText("Thank You!");
            }
        });

        R.addActionListener(new ActionListener()
        {
            public void actionPerformed(ActionEvent e)
            {
                firstName.setText("");
                lastName.setText("");
                M.setSelected(false);
                F.setSelected(false);
                py.setSelected(false);
                jv.setSelected(false);
                msg.setText("");
            }
        });
    }
}

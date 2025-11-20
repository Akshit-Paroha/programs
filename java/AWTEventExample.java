import java.awt.*;
import java.awt.event.*;

public class AWTEventExample extends Frame implements ActionListener
{
    Button b;

    AWTEventExample()
    {
        b = new Button("Click Me");
        b.setBounds(100, 100, 100, 50);
        add(b);
        b.addActionListener(this);  
        setSize(300, 200);
        setLayout(null);
        setVisible(true);
    }

    public void actionPerformed(ActionEvent e)
    {
        System.out.println("Button Clicked!");
    }

    public static void main(String[] args)
    {
        new AWTEventExample();
    }
}

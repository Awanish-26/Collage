import java.awt.*;
import java.awt.event.ActionListener;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;

// by extending Frame Class
public class AWT extends Frame {
    AWT() {
        Button button = new Button("Hit me!");
        TextField textfield = new TextField("type here ...");
        button.setBounds(500, 250, 80, 40);
        button.setBackground(Color.PINK);
        button.setForeground(Color.WHITE);
        textfield.setBounds(500, 200, 100, 30);
        add(textfield);
        add(button);
        setSize(1000, 500);
        setLayout(null);
        setVisible(true);
        addWindowListener(new WindowAdapter() {
            @Override
            public void windowClosing(WindowEvent e) {
                System.exit(0);
            }
        });
    }

    public static void main(String args[]) {
        new AWT();
    }

}

// By creating object of frame

// public class{

// AWT() {
// Frame fr = new Frame("Title:Be Hard");
// Button button = new Button("Hit me!");
// TextField textfield = new TextField("type here ...");
// button.setBounds(500, 250, 80, 40);
// button.setBackground(Color.PINK);
// button.setForeground(Color.WHITE);
// textfield.setBounds(500, 200, 100, 30);
// fr.add(textfield);
// fr.add(button);
// fr.setSize(1000, 500);
// fr.setLayout(null);
// fr.setVisible(true);
// fr.addWindowListener(new WindowAdapter() {
// @Override
// public void windowClosing(WindowEvent e) {
// System.exit(0);
// }
// });
// }

// public static void main(String args[]) {
// new AWT();
// }
// }
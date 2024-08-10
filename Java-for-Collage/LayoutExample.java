import java.awt.*;
import java.awt.event.*;

public class LayoutExample extends Frame {
    public LayoutExample() {
        setTitle("Layout Managers Example");

        // FlowLayout
        Panel flowPanel = new Panel();
        flowPanel.setLayout(new FlowLayout());
        flowPanel.add(new Button("Button 1"));
        flowPanel.add(new Button("Button 2"));
        flowPanel.add(new Button("Button 3"));

        // BorderLayout
        Panel borderPanel = new Panel();
        borderPanel.setLayout(new BorderLayout());
        borderPanel.add(new Button("North"), BorderLayout.NORTH);
        borderPanel.add(new Button("South"), BorderLayout.SOUTH);
        borderPanel.add(new Button("East"), BorderLayout.EAST);
        borderPanel.add(new Button("West"), BorderLayout.WEST);
        borderPanel.add(new Button("Center"), BorderLayout.CENTER);

        // GridLayout
        Panel gridPanel = new Panel();
        gridPanel.setLayout(new GridLayout(2, 2));
        gridPanel.add(new Button("Button 1"));
        gridPanel.add(new Button("Button 2"));
        gridPanel.add(new Button("Button 3"));
        gridPanel.add(new Button("Button 4"));

        // Set layout for the frame
        setLayout(new GridLayout(3, 1));
        add(flowPanel);
        add(borderPanel);
        add(gridPanel);

        // Set frame properties
        setSize(400, 400);
        setVisible(true);

        // Add window listener to handle close events
        addWindowListener(new WindowAdapter() {
            public void windowClosing(WindowEvent we) {
                System.exit(0);
            }
        });
    }

    public static void main(String[] args) {
        new LayoutExample();
    }
}

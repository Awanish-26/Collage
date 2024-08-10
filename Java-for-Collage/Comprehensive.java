import java.awt.*;
import java.awt.event.*;

public class Comprehensive extends Frame {
    Image img;

    public Comprehensive() {
        setTitle("Comprehensive AWT Example");

        // Load the image
        img = Toolkit.getDefaultToolkit().getImage("C:\\All-Program\\Basic-Start\\assets\\@wallandiadesk.jpg");
        // Create menu bar and menus
        MenuBar menuBar = new MenuBar();
        Menu fileMenu = new Menu("File");
        MenuItem exitItem = new MenuItem("Exit");
        fileMenu.add(exitItem);
        menuBar.add(fileMenu);
        setMenuBar(menuBar);

        // Add action listener to exit menu item
        exitItem.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent ae) {
                System.exit(0);
            }
        });

        // Create a layout with multiple panels
        setLayout(new BorderLayout());

        // Panel with FlowLayout
        Panel flowPanel = new Panel(new FlowLayout());
        flowPanel.add(new Button("Flow 1"));
        flowPanel.add(new Button("Flow 2"));
        flowPanel.add(new Button("Flow 3"));

        // Panel with GridLayout
        Panel gridPanel = new Panel(new GridLayout(2, 2));
        gridPanel.add(new Button("Grid 1"));
        gridPanel.add(new Button("Grid 2"));
        gridPanel.add(new Button("Grid 3"));
        gridPanel.add(new Button("Grid 4"));

        // Panel for image
        Panel imagePanel = new Panel() {
            public void paint(Graphics g) {
                g.drawImage(img, 0, 0, this);
            }
        };
        imagePanel.setPreferredSize(new Dimension(400, 300));

        // Add panels to frame
        add(flowPanel, BorderLayout.NORTH);
        add(gridPanel, BorderLayout.CENTER);
        add(imagePanel, BorderLayout.SOUTH);

        // Set frame properties
        setSize(500, 600);
        setVisible(true);

        // Add window listener to handle close events
        addWindowListener(new WindowAdapter() {
            public void windowClosing(WindowEvent we) {
                System.exit(0);
            }
        });
    }

    public static void main(String[] args) {
        new Comprehensive();
    }
}

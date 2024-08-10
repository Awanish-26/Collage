import java.awt.*;
import java.awt.event.*;

public class AWT2 extends Frame {
    public AWT2() {
        // Create a frame
        Frame frame = new Frame("Comprehensive AWT Example");

        // Create components
        Label nameLabel = new Label("Name:");
        TextField nameField = new TextField(20);

        Label genderLabel = new Label("Gender:");
        CheckboxGroup genderGroup = new CheckboxGroup();
        Checkbox maleCheckbox = new Checkbox("Male", genderGroup, false);
        Checkbox femaleCheckbox = new Checkbox("Female", genderGroup, false);

        Label skillsLabel = new Label("Skills:");
        Checkbox javaCheckbox = new Checkbox("Java");
        Checkbox pythonCheckbox = new Checkbox("Python");
        Checkbox cppCheckbox = new Checkbox("C++");

        Label countryLabel = new Label("Country:");
        Choice countryChoice = new Choice();
        countryChoice.add("USA");
        countryChoice.add("Canada");
        countryChoice.add("UK");
        countryChoice.add("Australia");

        Label hobbiesLabel = new Label("Hobbies:");
        List hobbiesList = new List(4, true);
        hobbiesList.add("Reading");
        hobbiesList.add("Traveling");
        hobbiesList.add("Cooking");
        hobbiesList.add("Sports");

        Label addressLabel = new Label("Address:");
        TextArea addressArea = new TextArea(5, 20);

        Label ageLabel = new Label("Age:");
        Scrollbar ageScrollbar = new Scrollbar(Scrollbar.HORIZONTAL, 25, 1, 0, 100);

        Button submitButton = new Button("Submit");

        // Set layout manager
        frame.setLayout(new FlowLayout());

        // Add components to frame
        frame.add(nameLabel);
        frame.add(nameField);
        frame.add(genderLabel);
        frame.add(maleCheckbox);
        frame.add(femaleCheckbox);
        frame.add(skillsLabel);
        frame.add(javaCheckbox);
        frame.add(pythonCheckbox);
        frame.add(cppCheckbox);
        frame.add(countryLabel);
        frame.add(countryChoice);
        frame.add(hobbiesLabel);
        frame.add(hobbiesList);
        frame.add(addressLabel);
        frame.add(addressArea);
        frame.add(ageLabel);
        frame.add(ageScrollbar);
        frame.add(submitButton);

        // Set frame properties
        frame.setSize(400, 600);
        frame.setVisible(true);

        // Add window listener to handle close events
        frame.addWindowListener(new WindowAdapter() {
            public void windowClosing(WindowEvent we) {
                System.exit(0);
            }
        });

        // Add action listener to the button
        submitButton.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent ae) {
                String name = nameField.getText();
                String gender = genderGroup.getSelectedCheckbox().getLabel();
                StringBuilder skills = new StringBuilder();
                if (javaCheckbox.getState())
                    skills.append("Java ");
                if (pythonCheckbox.getState())
                    skills.append("Python ");
                if (cppCheckbox.getState())
                    skills.append("C++ ");
                String country = countryChoice.getSelectedItem();
                String[] hobbies = hobbiesList.getSelectedItems();
                String address = addressArea.getText();
                int age = ageScrollbar.getValue();

                System.out.println("Name: " + name);
                System.out.println("Gender: " + gender);
                System.out.println("Skills: " + skills.toString().trim());
                System.out.println("Country: " + country);
                System.out.print("Hobbies: ");
                for (String hobby : hobbies) {
                    System.out.print(hobby + " ");
                }
                System.out.println();
                System.out.println("Address: " + address);
                System.out.println("Age: " + age);
            }
        });
    }

    public static void main(String[] args) {
        new AWT2();
    }
}

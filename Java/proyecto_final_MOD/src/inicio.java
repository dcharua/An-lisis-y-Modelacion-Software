import javax.swing.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;


public class inicio extends JFrame{
    private JTextField user;
    private JTextField pass;
    private JButton ingresarButton;
    private Admin a = new Admin();

    ingresarButton.addActionListener(new ActionListener() {
        @Override
        public void actionPerformed(ActionEvent actionEvent) {
            String name = user.getText();
            String pass = pass.getText();
            a.setAdmin(name, pass);
        }
    });
}

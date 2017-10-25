import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class VentanaSimple extends JFrame{
  public VentanaSimple(){
    setBounds(50, 50, 500, 500);
    JLabel l = new JLabel("Escribe tu nombre");
    JTextField nombre = new JTextField("               ");
    JButton btn = new JButton("saludo");
    JLabel saludo = new JLabel("");
    setLayout(new FlowLayout());
    add(l);
    add(nombre);
    add(btn);
    add(saludo);
    setDefaultCloseOperation(EXIT_ON_CLOSE);

    btn.addActionListener(new ActionListener (){
      @Override
      public void actionPerformed(ActionEvent ae){
        String name = nombre.getText();
        saludo.setText("hola " +name);
      }
    });

    setVisible(true);
  }
  public static void main(String[] args){

    VentanaSimple v = new VentanaSimple();
  }
}

package by.bsu.lab6task9.Main;

import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import java.time.LocalTime;

public class Main extends Frame implements ActionListener, Runnable{
    boolean flag;
   Thread t1=new Thread();
    Button stopButton,startButton;

    public Main(){
        super("Watch");

        setSize(new Dimension(600,670));
        this.setResizable(false);

        stopButton=new Button("Stop");
        startButton=new Button("Start");
        setLayout(new FlowLayout());
        add(stopButton);
        add(startButton);
        add(new ClockFace());
        stopButton.addActionListener(this);
        startButton.addActionListener(this);

        addWindowListener(new WindowAdapter(){
            public void windowClosing(WindowEvent e){
                System.exit(0);
            }
        });
        setVisible(true);
        t1=new Thread(this);
        t1.start();

    }
    public void run() {
        try {
            UIManager.setLookAndFeel(UIManager.getSystemLookAndFeelClassName());
        } catch (ClassNotFoundException | InstantiationException | IllegalAccessException | UnsupportedLookAndFeelException ex) {
            ex.printStackTrace();
        }
    }

    public class ClockFace extends JPanel {

        public ClockFace() {
                }

        @Override
        public Dimension getPreferredSize() {
            return new Dimension(600, 670);
        }

        @Override
        protected void paintComponent(Graphics g) {
            Graphics2D g2d = (Graphics2D) g.create();

            LocalTime now = LocalTime.now();
            int seconds = now.getSecond();
            int minutes = now.getMinute();
            int hours = now.getHour();

            g2d.setColor(Color.WHITE);
            g2d.fillRect(0, 0, 600, 600);
            g2d.setColor(Color.BLACK);
            g2d.translate(300, 300);

            for (int i = 0; i < 12; i++) {

                g2d.drawLine(0, -260, 0, -300);
                g2d.rotate(Math.PI / 6);

            }

            g2d.rotate(seconds * Math.PI / 30);
            g2d.drawLine(0, 0, 0, -290);

            g2d.rotate(2 * Math.PI - seconds * Math.PI / 30);
            g2d.rotate(minutes * Math.PI / 30);
            g2d.setStroke(new BasicStroke(3));
            g2d.drawLine(0, 0, 0, -250);

            g2d.rotate(2 * Math.PI - minutes * Math.PI / 30);
            g2d.rotate(hours * Math.PI / 6);
            g2d.setStroke(new BasicStroke(6));
            g2d.drawLine(0, 0, 0, -200);

            g2d.dispose();
        }
    }

    public void actionPerformed(ActionEvent ae){
        String str = ae.getActionCommand();
            Timer timer = new Timer(500, new ActionListener() {
                @Override
                public void actionPerformed(ActionEvent e) {
                    repaint();
                }
            });
            if(str.equals("Start")) {
            timer.start();
        } else if(str.equals("Stop")){
                System.exit(0);
            }
        }


    public static void main(String[] args) {
        Frame f=new Main();
    }

}

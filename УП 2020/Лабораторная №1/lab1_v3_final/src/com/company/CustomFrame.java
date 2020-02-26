package com.company;

import javax.swing.*;
import javax.swing.border.BevelBorder;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.geom.AffineTransform;
import java.awt.geom.Point2D;


public class CustomFrame extends JFrame implements Runnable {


    JLabel statusLabel = new JLabel();

    public CustomFrame() {

        Font font = new Font("Verdana", Font.PLAIN, 11);

        JMenuBar menuBar = new JMenuBar();
        JMenu frameMenu = new JMenu("Menu");
        menuBar.add(frameMenu);

        JMenuItem startItem = new JMenuItem("Start");
        startItem.setFont(font);
        frameMenu.add(startItem);

        JMenuItem exitItem = new JMenuItem("Exit");
        exitItem.setFont(font);
        frameMenu.add(exitItem);



        startItem.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent actionEvent) {
                GraphicsOnJPanel();
                newThread.start();
            }
        });

        exitItem.addActionListener(new exitApp());






        this.setJMenuBar(menuBar);

        addStatusBar();



    }

    static class exitApp implements ActionListener {
        public void actionPerformed(ActionEvent e) {
            System.exit(0);
        }
    }
    public void GraphicsOnJPanel () {
        setSize(500,500) ;

        setResizable(false);


        setContentPane(new JPanel() {
                           public void paint(Graphics g) {
                               super.paint(g);


                               setBackground(backColor);

                               Graphics2D g2 = (Graphics2D) g;

                               g2.setStroke(new BasicStroke(ourThickness));

                               Point2D p1 = new Point2D.Float(150, 250);
                               Point2D p2 = new Point2D.Float(250, 250);
                               line.addPoint((int) p1.getX(), (int) p1.getY());
                               line.addPoint((int) p2.getX(), (int) p2.getY());


                               g2.setColor(lineColor);

                               AffineTransform at =
                                       AffineTransform.getRotateInstance(
                                               Math.toRadians(degree), p2.getX(), p2.getY());

                               g2.draw(at.createTransformedShape(line));


                           }
                       }

        );

        statusLabel.setText("Animation started");
        statusLabel.setHorizontalAlignment(SwingConstants.LEFT);
        setLayout(new BorderLayout()); add(statusLabel, BorderLayout.PAGE_END);
    }

    public void addStatusBar() {

    }

    Polygon line = new Polygon();

    int degree = 0;

    public int ourThickness;
    public Color lineColor;
    public Color backColor;

    Thread newThread = new Thread(this::run);


    @Override
    public void run() {

        while(true) {
            try {
                try {
                    Thread.sleep(50);
                    degree += 1;

                    repaint();


                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
            } catch (Exception e) {
                e.printStackTrace();
            }
        }
    }

    public void setDefaultCloseOperation() {
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    }
}

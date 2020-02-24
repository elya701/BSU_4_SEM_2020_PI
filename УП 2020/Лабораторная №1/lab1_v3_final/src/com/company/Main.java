package com.company;

import javax.swing.*;
import java.awt.*;


public class Main {

    public static void main(String[] args) {
	CustomFrame ourFrame = new CustomFrame();

	ourFrame.setTitle("Frame App");







		ourFrame.ourThickness = Integer.parseInt(args[0]);
		ourFrame.lineColor = Color.decode(args[1]);
		ourFrame.backColor = Color.decode(args[2]);



	ourFrame.setSize(550,550);
	ourFrame.getContentPane().setBackground(Color.white);

	ourFrame.setDefaultCloseOperation();

	ourFrame.setVisible(true);


    }
}

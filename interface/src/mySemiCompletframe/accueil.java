package mySemiCompletframe;

import java.awt.BorderLayout;
import java.awt.EventQueue;

import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.border.EmptyBorder;
import javax.swing.JTextPane;
import javax.swing.UIManager;
import javax.swing.UnsupportedLookAndFeelException;

import java.awt.Color;
import javax.swing.border.BevelBorder;
import java.awt.Font;
import java.awt.Dimension;
import java.awt.GridBagLayout;
import java.awt.GridBagConstraints;
import javax.swing.JEditorPane;
import javax.swing.JTextField;
import javax.swing.JButton;
import javax.swing.border.LineBorder;
import javax.swing.plaf.nimbus.NimbusLookAndFeel;

import java.awt.event.ActionListener;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.awt.event.ActionEvent;

public class accueil extends JFrame {
	
	private JPanel contentPane;
	private JTextField chemin;
	
	void fermer() {
		this.dispose();
	} 

	/**
	 * Create the frame.
	 */
	public accueil() {
		super( "ALGOCOMP" );
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setBounds(100, 100, 500, 400);
		contentPane = new JPanel();
		contentPane.setBorder(new EmptyBorder(5, 5, 5, 5));
		setContentPane(contentPane);
		contentPane.setLayout(null);
		
		JTextPane txtpnAlgocomp = new JTextPane();
		txtpnAlgocomp.setBounds(0, 20, 484, 46);
		txtpnAlgocomp.setText("           << ALGOCOMP >>");
		txtpnAlgocomp.setSelectionColor(Color.BLACK);
		txtpnAlgocomp.setSelectedTextColor(Color.BLACK);
		txtpnAlgocomp.setPreferredSize(new Dimension(300, 46));
		txtpnAlgocomp.setForeground(Color.WHITE);
		txtpnAlgocomp.setFont(new Font("Tahoma", Font.BOLD, 30));
		txtpnAlgocomp.setFocusable(false);
		txtpnAlgocomp.setDisabledTextColor(Color.BLACK);
		txtpnAlgocomp.setCaretColor(Color.WHITE);
		txtpnAlgocomp.setBorder(new BevelBorder(BevelBorder.LOWERED, Color.CYAN, Color.CYAN, Color.GREEN, Color.GREEN));
		txtpnAlgocomp.setBackground(Color.BLACK);
		txtpnAlgocomp.setAutoscrolls(false);
		contentPane.add(txtpnAlgocomp);
		
		JEditorPane editorPane = new JEditorPane();
		editorPane.setText("                                                                Bonjour :) \r\n   Entrez le chemin du dossier principale de ALGOCOMP dans votre ordinateur : ");
		editorPane.setSelectionColor(Color.WHITE);
		editorPane.setForeground(Color.RED);
		editorPane.setFocusable(false);
		editorPane.setDisabledTextColor(Color.RED);
		editorPane.setBounds(0, 98, 484, 38);
		contentPane.add(editorPane);
		
		chemin = new JTextField();
		chemin.setText("C:\\..............\\ALGOCOMP");
		chemin.setFont(new Font("Tahoma", Font.PLAIN, 14));
		chemin.setColumns(10);
		chemin.setBounds(45, 147, 388, 31);
		contentPane.add(chemin);
		
		JButton button = new JButton("Entrer");
		button.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				// recuperation du chemin et son stockage dans un fichier chemin.txt
				String ch = chemin.getText();
				
				
				File file = new File(ch+"\\interface\\chemin.txt");
				FileWriter writer = null;
				try {
					writer = new FileWriter(file);
				} catch (IOException e1) {
					// TODO Auto-generated catch block
					e1.printStackTrace();
				}
				BufferedWriter bw = new BufferedWriter(writer);
				try {
					bw.write(ch);
					bw.close();
					writer.close();
				} catch (IOException e1) {
					// TODO Auto-generated catch block
					e1.printStackTrace();
				}
				if(ch != "") {
					// il faut declarer un fichier qui va contenir le chemin complet de dossier de se compilateur dans votre ordinateur 
					try {
						UIManager.setLookAndFeel( new NimbusLookAndFeel());
					} catch (UnsupportedLookAndFeelException e1) {
						// TODO Auto-generated catch block
						e1.printStackTrace();
					}
					
					fent g = new fent();
					fent.CH = ch;
					g.setVisible( true );
					g.setLocationRelativeTo(null);
					fermer();
				}
				else {
					System.out.println("il faut que vous entrez le chemin du dossier principale de ALGOCOMP.");
				}
			}
		});
		button.setFont(new Font("Tahoma", Font.BOLD, 16));
		button.setBounds(176, 189, 132, 43);
		contentPane.add(button);
		
		JTextPane textPane_1 = new JTextPane();
		textPane_1.setText("Faite par : \r\n\tIhda Mohamed\r\n\tKassi Hassan\r\n\tMahamat saleh Abakar Hamit\r\n\tCheradi Youness");
		textPane_1.setFont(new Font("Tahoma", Font.ITALIC, 11));
		textPane_1.setFocusable(false);
		textPane_1.setDisabledTextColor(Color.LIGHT_GRAY);
		textPane_1.setBackground(Color.WHITE);
		textPane_1.setBounds(0, 284, 484, 77);
		contentPane.add(textPane_1);
		
	}
	
	/**
	 * Launch the application.
	 */
	public static void main(String[] args) {
		EventQueue.invokeLater(new Runnable() {
			public void run() {
				try {
					accueil frame = new accueil();
					frame.setVisible(true);
					frame.setLocationRelativeTo(null);
				} catch (Exception e) {
					e.printStackTrace();
				}
			}
		});
	}
}

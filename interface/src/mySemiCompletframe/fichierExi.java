package mySemiCompletframe;

import java.awt.BorderLayout;
import java.io.BufferedReader;
import java.awt.EventQueue;

import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.JTextArea;
import javax.swing.border.EmptyBorder;
import javax.swing.JEditorPane;
import java.awt.Color;
import java.awt.Font;
import javax.swing.JButton;
import java.awt.event.ActionListener;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.awt.event.ActionEvent;

public class fichierExi extends JFrame {

	private JPanel contentPane;
	static NVfichier frame1;
	static fichierExi frame2;
	
	String cheminFE;
	
	void fermer() {
		this.dispose();
	} 

	/**
	 * Launch the application.
	 */
	/*public static void main(String[] args) {
		EventQueue.invokeLater(new Runnable() {
			public void run() {
				try {
					fichierExi frame = new fichierExi();
					frame.setVisible(true);
					frame.setLocationRelativeTo(null);
				} catch (Exception e) {
					e.printStackTrace();
				}
			}
		});
	}*/

	/**
	 * Create the frame.
	 */
	public fichierExi() {
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setBounds(100, 100, 500, 250);
		contentPane = new JPanel();
		contentPane.setBorder(new EmptyBorder(5, 5, 5, 5));
		contentPane.setLayout(new BorderLayout(0, 0));
		setContentPane(contentPane);
		
		JPanel panel = new JPanel();
		panel.setLayout(null);
		panel.setToolTipText("Nouveau fichier");
		contentPane.add(panel, BorderLayout.CENTER);
		
		JEditorPane editorPane = new JEditorPane();
		editorPane.setText("Entrez le nom ( le chemin absolue ) du fichier existant :");
		editorPane.setFont(new Font("Tahoma", Font.PLAIN, 14));
		editorPane.setEnabled(false);
		editorPane.setDisabledTextColor(Color.BLACK);
		editorPane.setBounds(20, 36, 387, 28);
		panel.add(editorPane);
		
		JEditorPane FE = new JEditorPane();
		FE.setFont(new Font("Tahoma", Font.BOLD, 14));
		FE.setBounds(20, 75, 429, 28);
		panel.add(FE);
		
		JButton button = new JButton("Entrer");
		button.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				cheminFE = FE.getText();
				java.util.Scanner lecteur = null;
				java.io.File fichier = new java.io.File(cheminFE);
				try {
					lecteur = new java.util.Scanner(fichier);
				} catch (FileNotFoundException e1) {
					// TODO Auto-generated catch block
					e1.printStackTrace();
				}
				if(lecteur.hasNextLine()) {
					fent.codeSource.setText(lecteur.nextLine());
					fent.codeSource.append("\n");
				}
				while(lecteur.hasNextLine()) {
					fent.codeSource.append(lecteur.nextLine());
					fent.codeSource.append("\n");
				}
				
				fent.erreursCompilation.setText("");
				fent.resultatsExe.setText("");
				fermer();
			}
		});
		button.setFont(new Font("Tahoma", Font.BOLD, 14));
		button.setBounds(186, 133, 113, 34);
		panel.add(button);
	}

}

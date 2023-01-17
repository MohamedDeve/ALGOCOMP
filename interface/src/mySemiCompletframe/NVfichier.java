package mySemiCompletframe;

import java.awt.BorderLayout;
import java.awt.EventQueue;

import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.border.EmptyBorder;
import javax.swing.JEditorPane;
import java.awt.Color;
import java.awt.Font;
import javax.swing.JButton;
import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;

public class NVfichier extends JFrame {
	
	private JPanel contentPane;
	String cheminNF;
	
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
					NVfichier frame = new NVfichier();
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
	public NVfichier() {
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
		editorPane.setText("Entrez le nom ( le chemin absolue ) de votre nouveau fichier :");
		editorPane.setFont(new Font("Tahoma", Font.PLAIN, 14));
		editorPane.setEnabled(false);
		editorPane.setDisabledTextColor(Color.BLACK);
		editorPane.setBounds(22, 36, 387, 28);
		panel.add(editorPane);
		
		JEditorPane NF = new JEditorPane();
		NF.setFont(new Font("Tahoma", Font.BOLD, 14));
		NF.setBounds(22, 77, 427, 28);
		panel.add(NF);
		
		JButton button = new JButton("Entrer");
		button.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				cheminNF = NF.getText();
				fent.codeSource.setText("");
				fent.erreursCompilation.setText("");
				fent.resultatsExe.setText("");
				fermer();
			}
		});
		button.setFont(new Font("Tahoma", Font.BOLD, 14));
		button.setBounds(186, 131, 113, 34);
		panel.add(button);
	}

}

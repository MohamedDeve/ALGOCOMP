package mySemiCompletframe;

import java.awt.BorderLayout;
import javax.swing.ImageIcon;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.JScrollPane;
import javax.swing.JSplitPane;
import javax.swing.JTextArea;
import javax.swing.JToolBar;
import javax.swing.UIManager;
import javax.swing.plaf.nimbus.NimbusLookAndFeel;
import java.awt.Color;
import java.awt.Dimension;
import java.awt.EventQueue;
import java.awt.Component;
import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;
import java.awt.ComponentOrientation;
import java.awt.SystemColor;
import javax.swing.SwingConstants;
import javax.swing.border.LineBorder;
import java.awt.Insets;
import java.awt.Cursor;
import java.awt.event.FocusAdapter;
import java.awt.event.FocusEvent;
import java.awt.event.MouseMotionAdapter;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.awt.event.MouseEvent;
import java.awt.Point;
import javax.swing.JSeparator;
import java.awt.Font;
import javax.swing.JEditorPane;

public class fent extends JFrame{
	private static final long serialVersionUID = 1L;
	private JPanel pan;
	private JToolBar toolBar;
	static JTextArea codeSource;
	static JTextArea erreursCompilation;
	static JTextArea resultatsExe;
	static NVfichier frame1;
	static fichierExi frame2;
	static String CH;
	int NFEstClicke = 0;
	int FEEstClicke = 0;
	String erreurs = " ";
	String nomFichierC;
	
	void fermer() {
		this.dispose();
	} 
	
	public fent() {
		super( "ALGOCOMP" );
		setBackground(Color.WHITE);
		setSize( 1100, 600 );
		setLocationRelativeTo( null );
		setDefaultCloseOperation( JFrame.DISPOSE_ON_CLOSE );
		
		pan = new JPanel();
		pan.setBackground(new Color(230, 230, 250));
		pan.setLayout( new BorderLayout());
		pan.add( SplitPane() );
		
		setContentPane( pan );
		
		toolBar = new JToolBar();
		toolBar.setBackground(Color.YELLOW);
		toolBar.setForeground(Color.BLUE);
		toolBar.setBorder(new LineBorder(new Color(255, 255, 255), 2));
		toolBar.setEnabled(false);
		toolBar.setFocusTraversalKeysEnabled(false);
		toolBar.setFocusable(false);
		toolBar.setMargin(new Insets(0, 88, 0, 0));
		toolBar.setOpaque(false);
		toolBar.setPreferredSize(new Dimension(1100, 40));
		toolBar.setSize(new Dimension(110, 50));
		toolBar.setAlignmentY(Component.BOTTOM_ALIGNMENT);
		toolBar.setFloatable(false);
		pan.add(toolBar, BorderLayout.NORTH);
		
		JButton boutonCompilation = new JButton("Compiler");
		boutonCompilation.setFont(new Font("SansSerif", Font.BOLD, 14));
		boutonCompilation.addMouseMotionListener(new MouseMotionAdapter() {
			@Override
			public void mouseDragged(MouseEvent e) {
				
			}
		});
		boutonCompilation.addFocusListener(new FocusAdapter() {
			@Override
			public void focusGained(FocusEvent e) {
			}
		});
		boutonCompilation.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
			// la partie du code qui permet de copier notre code source d'algorithme dans un fichier source
				File Nfile = null;
				
				File file = new File(CH+"\\Generation\\algo.txt");
				String code = codeSource.getText();
				
				if(NFEstClicke == 1 ) {
					Nfile = new File(frame1.cheminNF);
				}
				
				// determination du nom de l algo (nom du fichier .c finale a executer)
				nomFichierC = code.substring(5);
				int indexFin = 1;
				int i = 0;
				char c = nomFichierC.charAt(i);
				while(c != ' ' && c != '\n') {
					indexFin++;
					i++;
					c = nomFichierC.charAt(i);
				}
				nomFichierC = nomFichierC.substring(0, indexFin-1);
				
				// ecrire dans le fichier algo.txt
				FileWriter writer = null;
				try {
					writer = new FileWriter(file);
				} catch (IOException e1) {
					// TODO Auto-generated catch block
					e1.printStackTrace();
				}
				BufferedWriter bw = new BufferedWriter(writer);
				try {
					bw.write(code);
					bw.close();
					writer.close();
				} catch (IOException e1) {
					// TODO Auto-generated catch block
					e1.printStackTrace();
				}
				
				// ecrire dans le nouveau fichier cree par l'utilisateur
				if(NFEstClicke ==1 ) {
					FileWriter writerN = null;
					try {
						writerN = new FileWriter(Nfile);
					} catch (IOException e1) {
						// TODO Auto-generated catch block
						e1.printStackTrace();
					}
					BufferedWriter bwN = new BufferedWriter(writerN);
					try {
						bwN.write(code);
						bwN.close();
						writerN.close();
					} catch (IOException e1) {
						// TODO Auto-generated catch block
						e1.printStackTrace();
					}
				}
				
			// la partie du code qui permet de compiler le code source de notre algorithme et afficher des erreurs de la compilation dans la place des erreurs
				try {
					Process processus = Runtime.getRuntime().exec("cmd.exe /c" + "cd \\ && " + "cd "+ CH + "\\Generation && " + "prog.exe < " + "algo.txt");
					StringBuilder resultat = new StringBuilder();
					BufferedReader lecteur = new BufferedReader(new InputStreamReader(processus.getInputStream()));
					
					String ligne;
					while((ligne = lecteur.readLine()) != null) {
						resultat.append(ligne + "\n");
					}
					
					erreurs = resultat.toString();
					erreursCompilation.setText(erreurs);
				}catch(IOException e1){
					e1.printStackTrace();
				}
				
			}
		});
		boutonCompilation.setBorder(new LineBorder(Color.BLUE));
		boutonCompilation.setBackground(new Color(128, 128, 128));
		boutonCompilation.setCursor(Cursor.getPredefinedCursor(Cursor.DEFAULT_CURSOR));
		boutonCompilation.setFocusable(false);
		boutonCompilation.setForeground(new Color(0, 0, 139));
		boutonCompilation.setPreferredSize(new Dimension(100, 40));
		boutonCompilation.setSize(new Dimension(500, 40));
		toolBar.add(boutonCompilation);
		
		JSeparator separator = new JSeparator();
		separator.setPreferredSize(new Dimension(10, 30));
		toolBar.add(separator);
		
		JButton boutonExecution = new JButton("Executer");
		boutonExecution.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				// la partie du code qui permet dexecuter le programme c obteneue apres la conversion de l'algo en c est l'afficher dans la place du resultat d'execution
				String resuExec;
				erreurs = erreursCompilation.getText();
				if(erreurs.equals("DEBUT compilation : \nFIN compilation : \n")) {
					try {
						Process processus = Runtime.getRuntime().exec("cmd.exe /c" + "cd \\ && " + "cd "+ CH + "\\Generation && " +  "gcc -c " + nomFichierC + ".c  && " + "gcc -c fonction.c && "  +  "gcc -o resTest " + nomFichierC + ".o fonction.o && resTest");
						StringBuilder resultat = new StringBuilder();
						BufferedReader lecteur = new BufferedReader(new InputStreamReader(processus.getInputStream()));
						
						String ligne;
						while((ligne = lecteur.readLine()) != null) {
							resultat.append(ligne + "\n");
						}
	
						resuExec = resultat.toString();
						resultatsExe.setText(resuExec);
					}catch(IOException e1){
						e1.printStackTrace();
					}
				}
				else {
					resultatsExe.setForeground(Color.RED);
					resultatsExe.setText("==> Il faut dabord corriger les erreurs de la compilation.");
				}
			}
		});
		boutonExecution.setFont(new Font("SansSerif", Font.BOLD, 14));
		boutonExecution.setBorder(new LineBorder(Color.BLUE));
		boutonExecution.setPreferredSize(new Dimension(100, 40));
		boutonExecution.setFocusable(false);
		boutonExecution.setForeground(new Color(0, 0, 139));
		toolBar.add(boutonExecution);
		
		JSeparator separator_1 = new JSeparator();
		separator_1.setPreferredSize(new Dimension(10, 30));
		toolBar.add(separator_1);
		
		JButton btnNouveauFichier = new JButton("Nouveau Fichier");
		btnNouveauFichier.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				NFEstClicke = 1;
				frame1 = new NVfichier();
				frame1.setVisible(true);
				frame1.setLocationRelativeTo(null);
			}
		});
		btnNouveauFichier.setPreferredSize(new Dimension(150, 40));
		btnNouveauFichier.setForeground(new Color(0, 0, 139));
		btnNouveauFichier.setFont(new Font("SansSerif", Font.BOLD, 14));
		btnNouveauFichier.setFocusable(false);
		btnNouveauFichier.setBorder(new LineBorder(Color.BLUE));
		toolBar.add(btnNouveauFichier);
		
		JSeparator separator_2 = new JSeparator();
		separator_2.setPreferredSize(new Dimension(10, 30));
		toolBar.add(separator_2);
		
		JButton btnFichierExistant = new JButton("Fichier Existant");
		btnFichierExistant.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				FEEstClicke = 1;
				frame2 = new fichierExi();
				frame2.setVisible(true);
				frame2.setLocationRelativeTo(null);
			}
		});
		btnFichierExistant.setPreferredSize(new Dimension(150, 40));
		btnFichierExistant.setForeground(new Color(0, 0, 139));
		btnFichierExistant.setFont(new Font("SansSerif", Font.BOLD, 14));
		btnFichierExistant.setFocusable(false);
		btnFichierExistant.setBorder(new LineBorder(Color.BLUE));
		toolBar.add(btnFichierExistant);
		
		
		
	}
	
	


	public JSplitPane SplitPane() {
		
		codeSource = new JTextArea();
		codeSource.setFont(new Font("Calibri Light", Font.BOLD, 16));
		codeSource.setBorder(new LineBorder(new Color(0, 0, 0), 2));
		JScrollPane scrolltextHaut = new JScrollPane( codeSource );
		scrolltextHaut.setBorder(new LineBorder(Color.LIGHT_GRAY));
		scrolltextHaut.setBackground(Color.BLACK);
		
		erreursCompilation = new JTextArea();
		erreursCompilation.setFocusable(false);
		erreursCompilation.setSelectedTextColor(Color.WHITE);
		erreursCompilation.setForeground(Color.RED);
		erreursCompilation.setFont(new Font("SansSerif", Font.BOLD, 14));
		erreursCompilation.setBorder(new LineBorder(new Color(255, 0, 0)));
		JScrollPane scrolltextAreaCenter = new JScrollPane( erreursCompilation);
		scrolltextAreaCenter.setBorder(new LineBorder(null));
		
		
		JSplitPane centerSplitPane = new JSplitPane(JSplitPane.VERTICAL_SPLIT,scrolltextHaut , scrolltextAreaCenter );
		
		JEditorPane dtrpnLesErreursDu = new JEditorPane();
		dtrpnLesErreursDu.setText("                                                          les erreurs du compilation");
		dtrpnLesErreursDu.setForeground(Color.BLACK);
		dtrpnLesErreursDu.setFont(new Font("SansSerif", Font.BOLD, 14));
		dtrpnLesErreursDu.setEnabled(false);
		dtrpnLesErreursDu.setDisabledTextColor(Color.RED);
		dtrpnLesErreursDu.setBackground(Color.BLACK);
		scrolltextAreaCenter.setColumnHeaderView(dtrpnLesErreursDu);
		
		JEditorPane dtrpnVotreAlgorithme = new JEditorPane();
		dtrpnVotreAlgorithme.setDisabledTextColor(Color.BLACK);
		dtrpnVotreAlgorithme.setForeground(Color.BLACK);
		dtrpnVotreAlgorithme.setBackground(Color.BLACK);
		dtrpnVotreAlgorithme.setEnabled(false);
		dtrpnVotreAlgorithme.setFont(new Font("SansSerif", Font.BOLD, 14));
		dtrpnVotreAlgorithme.setText("                                                              votre algorithme");
		scrolltextHaut.setColumnHeaderView(dtrpnVotreAlgorithme);
		centerSplitPane.setContinuousLayout(false);
		centerSplitPane.setForeground(new Color(0, 0, 0));
		centerSplitPane.setBackground(Color.BLACK);
		centerSplitPane.setResizeWeight( 0.60 );
		
	    resultatsExe = new JTextArea();
	    resultatsExe.setFocusable(false);
	    resultatsExe.setFont(new Font("SansSerif", Font.BOLD, 14));
	    resultatsExe.setBorder(new LineBorder(new Color(0, 255, 0)));
		JScrollPane scrolltextAreaRight = new JScrollPane( resultatsExe );
		
		JSplitPane horizontalSplitPane = new JSplitPane(JSplitPane.HORIZONTAL_SPLIT,centerSplitPane,scrolltextAreaRight);
		
		JEditorPane dtrpnResultatDexecution = new JEditorPane();
		dtrpnResultatDexecution.setText("                                   resultat d'execution");
		dtrpnResultatDexecution.setForeground(Color.BLACK);
		dtrpnResultatDexecution.setFont(new Font("SansSerif", Font.BOLD, 14));
		dtrpnResultatDexecution.setEnabled(false);
		dtrpnResultatDexecution.setDisabledTextColor(new Color(0, 100, 0));
		dtrpnResultatDexecution.setBackground(Color.BLACK);
		scrolltextAreaRight.setColumnHeaderView(dtrpnResultatDexecution);
		horizontalSplitPane.setResizeWeight( 0.60 );
	    return  horizontalSplitPane;
	}
	
}

import java.util.*;
import java.io.*;
import java.lang.*;
import java.util.Random;


class Player {
	private String name;// Represents the Players name
	Scanner sc = new Scanner(System.in);
	// sc will help to take inputs from keyboard

	public String getName() {
		return name;
	}

	public void setName(String name) {
		this.name = name;
	}

	public void askName() {// Will let the user enter his name
		System.out.println("Please enter your name: ");
		name = sc.next();
	}

	public int getInput() {
		// This function lets the user do the selection among
		// ROCK PAPER SCISSORS
		// and return what has been selected
		System.out.println("Select  ROCK  PAPER SCISSOR");

		String input = sc.next();
		input = input.toUpperCase();
		char c = input.charAt(0);
		// checking the 1st character in the input
		if (c == 'R')
			return Driver.ROCK;
		else if (c == 'P')
			return Driver.PAPER;
		else if (c == 'S')
			return Driver.SCISSORS;
		else {
			getInput();
			return 0;
		}
	}

	public boolean playAgain() {
		// This function will ask if the user wants to
		// play again and return true or false accordingly.
		sc = new Scanner(System.in);
		System.out.print("Do you want to play again? ");
		String userInput = sc.nextLine();
		userInput = userInput.toUpperCase();
		return userInput.charAt(0) == 'Y';
	}
}


class Computer {
	// This function helps the computer do the selection among ROCK,
	// PAPER,SCISSORS
	// we have used Random class from java.util.
	public int getInput() {
		Random random = new Random();
		int input = random.nextInt(3) + 1;
		return input;
	}
}

class Driver {
	//These instance variables will act as constants through out the project
	public static final int ROCK = 1;
	public static final int PAPER = 2;
	public static final int SCISSORS = 3;

	//This function will help to display who selected what
	public static void display(String who, int s) {
		switch (s) {
		case Driver.ROCK:
			System.out.print(who + " selected ROCK   ");
			break;
		case Driver.PAPER:
			System.out.print(who + " selected PAPER   ");
			break;
		case Driver.SCISSORS:
			System.out.print(who + " selected SCISSORS   ");
			break;
		default:
			break;
		}
	}
	//This function contains the actual buisness logic
	//and help to decide who won
	public static int compareSelections(int userSelection, int computerSelection) {
		if(userSelection==computerSelection) return 0;
		switch (userSelection) {
		case ROCK:
			return (computerSelection == SCISSORS ? 1 : -1);

		case PAPER:
			return (computerSelection == ROCK ? 1 : -1);

		case SCISSORS:
			return (computerSelection == PAPER ? 1 : -1);
		}
		return 0;
	}
}

class RPS {
	//Instance variables declaration
	private Player player;
	private Computer computer;
	private int playerScore;
	private int computerScore;
	private int numberOfGames;

	//Default Constructor initializing the instance variables
	public RPS() {
		player = new Player();
		computer = new Computer();
		playerScore = 0;
		computerScore = 0;
		numberOfGames = 0;
	}

	//This function is called recursively till the player wants to play.
	//It is even exited if the user of computer completes the first 5 wins.
	public void startGame() {
		int playerinput = player.getInput();
		Driver.display(player.getName(), playerinput);
		// Get moves
		int computerinput = computer.getInput();
		Driver.display("computer", computerinput);
		// Compare moves and determine winner
		int compareResult=Driver.compareSelections(playerinput, computerinput);
		switch (compareResult) {
		case 0: // Tie
			System.out.println("Tie!");
			break;
		case 1: // player wins
			System.out.println(player.getName()+ " Beats " + "computer" +" You won!");
			playerScore++;
			break;
		case -1: // Computer wins
			System.out.println("Computer" +" Beats "+ player.getName()+" You Lost!");
			computerScore++;
			break;
		}
		numberOfGames++;
		if(playerScore==5)
		{
			System.out.println(player.getName()+" HAS WON THE GAME.............");
			new RPS();
		}
		if(computerScore==5)
		{
			System.out.println("Computer "+" HAS WON THE GAME............");
			new RPS();
		}
		// Ask the player to play again
		if (player.playAgain()) {
			System.out.println();
			startGame();
		} else {
			printStats();
		}
	}
	//helps to get the users name
	public void getplayerName() {
		player.askName();
	}
	//Prints the result.
	public void printStats()
	{
		System.out.println("Number of games played is "+numberOfGames);
		System.out.println(player.getName()+"'s score "+playerScore);
		System.out.println("Computers score "+computerScore);
	}
}


class Main {
 
 	public static void main(String[] args) {

		RPS rps = new RPS();//Initialization occured.
		rps.getplayerName();//Getting user name
		rps.startGame();
	}   
    
}

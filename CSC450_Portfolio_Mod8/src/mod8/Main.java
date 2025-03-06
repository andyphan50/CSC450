package mod8;
import java.util.Scanner;
import java.util.concurrent.locks.Lock; 
import java.util.concurrent.locks.ReentrantLock; 
import java.util.concurrent.atomic.AtomicInteger;

public class Main {
	//Create a Lock object to be used by the threads to mutex resource
	private static final Lock lock = new ReentrantLock(); 
	//create a shared counter which will be the shared resource for the threads
	private static final AtomicInteger sharedCounter = new AtomicInteger(0); 
	

	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		System.out.print("Please enter your name to start the coundown:");
		String userInput = scanner.nextLine(); 
		userInput = sanitizeInput(userInput);
		
		//creating threads initialized with instances of our count functions
		Thread countUp = new Thread(new CountUp()); 
		Thread countDown = new Thread(new CountDown()); 
		
		//starts execution of our countUp thread
		countUp.start(); 
		try {
			countUp.join();  //Wait for the countUp thread to finish
		} catch(InterruptedException e) {
			e.printStackTrace();
		}
		
		countDown.start(); 
		
		scanner.close(); 

	}
	
	//function to sanitize user input
	private static String sanitizeInput(String input) {
		//remove any non-alphanumeric characters using regEx
		return input.replaceAll("[^a-zA-Z0-9]", "");
				
	}
	
	//In java for a function to be recognized by a thread it must implement the Runnable interface
	//it includes only the run abstract function which defines the code that should be executed when 
	//the task is to run 
	static class CountUp implements Runnable {
		@Override
		public void run() {
			for (int i=1; i <=20; i++) {
				//Acquiring lock 
				Main.lock.lock(); 
				try {
					System.out.println("Count Up: " + Main.sharedCounter.get()); 
					Main.sharedCounter.incrementAndGet(); 
					Thread.sleep(500);
				} catch (InterruptedException e) {
					e.printStackTrace();
				} finally {
					//releasing lock when function has finished executing
					Main.lock.unlock(); 
				}
			}
		}
		
	}


	static class CountDown implements Runnable {
		public void run() {
			for (int i=20; i >=0; i--) {
				//Acquiring lock 
				Main.lock.lock();
				try {
					System.out.println("Count Down: " + Main.sharedCounter.get()); 
					Main.sharedCounter.decrementAndGet(); 
					Thread.sleep(500);
				} catch (InterruptedException e) {
					e.printStackTrace();
				} finally {
					//releasing lock when function has finished executing
					Main.lock.unlock(); 
				}
			}
		}
		
	}

}




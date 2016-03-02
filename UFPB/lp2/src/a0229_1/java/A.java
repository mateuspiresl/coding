package a0229_1.java;

import java.util.concurrent.Executor;
import java.util.concurrent.Executors;
import java.util.concurrent.LinkedBlockingQueue;

public class A {
	
	public static void main(String[] args)
	{
		Executor e = Executors.newCachedThreadPool();
		
		e.execute(new Runnable() {
			@Override
			public void run() {
				System.out.println(this);
			}
		});
		e.execute(new Runnable() {
			@Override
			public void run() {
				System.out.println(this);
			}
		});
		e.execute(new Runnable() {
			@Override
			public void run() {
				System.out.println(this);
			}
		});
		e.execute(new Runnable() {
			@Override
			public void run() {
				System.out.println(this);
			}
		});
		e.execute(new Runnable() {
			@Override
			public void run() {
				System.out.println(this);
			}
		});
	}
	
}

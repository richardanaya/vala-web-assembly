// classes work!
class Calculator {
	public static int add(int a, int b){
		return a+b;
	}
}

// Entry functions need some special sugar to expose them properly
[CCode (cname = "__attribute__((visibility(\"default\"))) boo")]
public int add(int a, int b){
	return Calculator.add(a,b);
}

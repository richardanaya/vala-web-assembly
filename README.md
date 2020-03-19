# Vala and web assembly

It appears as though its possible to generate web assembly using the vala compiler. Unfortunately, `glib` doesn't compile out of the box for some very minor reasons. This repo contains a working glib and various example of testing out the capabilities of vala.

Changes to glib:
* removed gthreads header
* disabled an assertion

## dependencies
```
sudo dnf install clang llvm lld vala glib-devel
```

## example
```vala
// classes work like normal!
class Calculator {
	public static int add(int a, int b){
		return a+b;
	}
}

// Entry functions need some special sugar to expose them properly
[CCode (cname = "__attribute__((visibility(\"default\"))) add")]
public int add(int a, int b){
	return Calculator.add(a,b);
}

```

See it working [here](https://richardanaya.github.io/vala-web-assembly/examples/add/index.html)

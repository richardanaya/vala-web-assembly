# Vala and web assembly

It appears as though its possible to generate web assembly using the vala compiler. Unfortunately, `glib` doesn't compile out of the box for some very minor reasons. This repo contains a working glib and various example of testing out the capabilities of vala.

dependencies:
```
sudo dnf install clang llvm lld vala glib-devel
```

Example:
```vala
[CCode (cname = "__attribute__((visibility(\"default\"))) boo")]
public int add(int a, int b){
	return a+b;
}
```

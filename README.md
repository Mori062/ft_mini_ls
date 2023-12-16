<h1 align="center">
	ft_mini_ls
</h1>

<p align="center">
	<b><i>As simple as listing the files in a directory.</i></b><br>
</p>

---

## About the project

> _In short: This project will make you recode the command “ls”_


## Usage

### Requirements

The function is written in C language and thus needs the **`cc` compiler** and some standard **C libraries** to run.

### Instructions

**1. Compiling the program**

To compile, go to the program path and run:

```shell
make
```

**2. Executing the program**

To execute the program, run:

```terminal
./ft_mini_ls
```

Notice : All these behaviors are designed to be the same as `ls -1tr`

## Testing

You can use this command to test the right outputs:

```shell
diff <(./ft_mini_ls) <(ls -1tr) && echo OK || echo KO
```

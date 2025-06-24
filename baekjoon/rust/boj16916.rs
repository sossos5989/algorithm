use std::io;

fn main() {
    let mut text = String::new();
    let mut pattern = String::new();
    io::stdin().read_line(&mut text).unwrap();
    io::stdin().read_line(&mut pattern).unwrap();
    let text = text.trim_end();
    let pattern = pattern.trim_end();
    let ans = if text.contains(pattern) { 1 } else { 0 };
    println!("{}", ans);
}
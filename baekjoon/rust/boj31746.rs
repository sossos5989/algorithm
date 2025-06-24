use std::io;

fn main() {
    let mut input = String::new();
    io::stdin().read_line(&mut input).unwrap();
    let x: usize = input.trim().parse().unwrap();
    match x % 2 {
        0 => println!("SciComLove"),
        1 => println!("evoLmoCicS"),
        _ => {},
    }
}
use std::io;

fn func(chars: &[char], idx: usize, a: i32, b: i32) -> char {
    if idx + 1 >= chars.len() {
        return if a > b { 'A' } else { 'B' };
    }
    
    let score = chars[idx + 1].to_digit(10).unwrap() as i32;
    if chars[idx] == 'A' {
        func(&chars, idx + 2, a + score, b)
    }
    else {
        func(&chars, idx + 2, a, b + score)
    }
}

fn main() {
    let mut input = String::new();
    io::stdin().read_line(&mut input).unwrap();
    let chars: Vec<char> = input.chars().collect();

    let f = func(&chars, 0, 0, 0);
    println!("{}", f);
}
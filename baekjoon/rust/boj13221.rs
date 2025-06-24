use std::{
    io::{self, BufWriter, Read, Write},
};

fn main() {
    let mut buf = String::new();
    let mut writer = BufWriter::new(std::io::stdout());
    io::stdin().read_to_string(&mut buf).unwrap();
    let mut input = buf.split_ascii_whitespace();
    let x: isize = input.next().unwrap().parse().unwrap();
    let y: isize = input.next().unwrap().parse().unwrap();
    let n: isize = input.next().unwrap().parse().unwrap();

    let mut ans_x: isize = input.next().unwrap().parse().unwrap();
    let mut ans_y: isize = input.next().unwrap().parse().unwrap();
    
    for _ in 1..n {
        let taxi_x: isize = input.next().unwrap().parse().unwrap();
        let taxi_y: isize= input.next().unwrap().parse().unwrap();

        if (x - ans_x).abs() + (y - ans_y).abs() > (x - taxi_x).abs() + (y - taxi_y).abs() {
            ans_x = taxi_x;
            ans_y = taxi_y;
        }
    }

    writeln!(writer, "{} {}", ans_x, ans_y).unwrap();
}
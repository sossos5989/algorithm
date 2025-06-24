use std::{
    collections::VecDeque,
    io::{self, BufWriter, Read, Write},
};

fn main() {
    let mut buf = String::new();
    let mut writer = BufWriter::new(std::io::stdout());
    io::stdin().read_to_string(&mut buf).unwrap();
    let mut input = buf.split_ascii_whitespace();
    let n: usize = input.next().unwrap().parse().unwrap();
    let mut q = VecDeque::new();

    for _ in 0..n {
        match input.next().unwrap() {
            "push" => q.push_back(input.next().unwrap().parse::<isize>().unwrap()),
            "pop" => writeln!(writer, "{}", q.pop_front().unwrap_or(-1)).unwrap(),
            "size" => writeln!(writer, "{}", q.len()).unwrap(),
            "empty" => writeln!(writer, "{}", if q.is_empty() { 1 } else { 0 }).unwrap(),
            "front" => writeln!(writer, "{}", q.front().unwrap_or(&-1)).unwrap(),
            "back" => writeln!(writer, "{}", q.back().unwrap_or(&-1)).unwrap(),
            _ => {}
        }
    }
}
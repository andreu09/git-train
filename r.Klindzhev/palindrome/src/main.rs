use std::io;
fn main() {
    println!("Введите значение \n");
    read_input()
}

fn read_input(){
    let mut s = String::new();

    io::stdin()
        .read_line(&mut s)
        .unwrap();
    
    println!("{}", check_palindrome(s));
}

fn check_palindrome(s: String) -> bool {
    let str: Vec<char> = s.chars().filter(|f| f.is_alphanumeric()).map(|f| f.to_ascii_lowercase()).collect();
    let phrase: String = str.clone().into_iter().collect();
    let rev_phrase: String = str.clone().into_iter().rev().collect();
    phrase == rev_phrase 
}


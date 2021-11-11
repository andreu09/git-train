use std::io;
fn main() {
    println!("Укажите номер билета");
    collect_number();
}

fn collect_number(){
    loop {
        let mut n = String::new();
        
        io::stdin()
            .read_line(&mut n)
            .unwrap();
        
        let even = ((n.len() + 1) % 2) as i32 ;

        if even.eq(&0) {
            let number: i32 = match n.trim().parse() {
                Ok(num) => num,
                Err(_) => {
                    println!("Пожалуйста, введите целое число");
                    continue
                }
            };

            str_spliting(number);

            break;
        } else {
            println!("Номер билета должен содержать четное количество символов");
            continue
        }
    } 
}

fn str_spliting(number: i32){
    let num_as_str = number.to_string();
    let center_of_string = num_as_str.len()/2;

    let first_part  = &num_as_str[..center_of_string].chars()
        .map(|c| c.to_digit(10).unwrap()).sum::<u32>();

    let second_part = &num_as_str[center_of_string..].chars()
        .map(|c| c.to_digit(10).unwrap()).sum::<u32>();
    
    match first_part == second_part {
        true => println!("У вас счастливый билет! Поздравляю!"),
        false => println!("Не в этот раз :-)"),
    }
}

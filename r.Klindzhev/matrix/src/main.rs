use std::vec;
use std::io;
use rand::{Rng, distributions::{Uniform}}; 
use itertools::Itertools;

enum Direction {
    Down,
    Up,
    Left,
    Right
}
fn main() {
    println!("Укажите значение n");

    loop {
        let mut n = String::new();

        io::stdin()
        .read_line(&mut n)
        .unwrap();

        let number: usize = match n.trim().parse() {
            Ok(num) => num,
            Err(_) => {
                println!("Пожалуйста, введите целое число");
                continue
            }
        };

        generate_matrix(number);
        break
    } 
            
    
}

fn generate_matrix(n : usize) {
    let n = n;
    let matrix_size = (2 * n) - 1;
    let matrix: Vec<Vec<i32>> =
        std::iter::from_fn(|| Some(rand::thread_rng()
        .sample_iter(Uniform::from(0..99))
        .take(matrix_size).collect()))
            .take(matrix_size)
            .collect();

    println!("Вы получили следующую матрицу:");
    println!("{:?}", matrix.iter().format("\n"));

    get_spiral(matrix);
}


fn get_spiral(matrix: Vec<Vec<i32>>){  
    let mut matrix = matrix;
    let mut spiral = vec![];
    let mut direction = Direction::Right;
    
    while matrix.len() > 0 && matrix.iter().any(|v| v.len() > 0) {
        match direction {
            Direction::Down => { matrix.iter_mut().for_each(|v| spiral.push(v.pop().unwrap()))},
            Direction::Up => { matrix.iter_mut().rev().for_each(|v| spiral.push(v.remove(0)))},
            Direction::Right => { spiral.append(&mut matrix.remove(0))},
            Direction::Left => { matrix.pop().unwrap().iter().rev().for_each(|i| spiral.push(*i))} 
        }
        direction = change_direction(direction);
    }

    println!("Результат:",);
    println!("{:?}", spiral.into_iter().rev().collect::<Vec<i32>>());
        
}

fn change_direction(direction: Direction) -> Direction {
    match direction {
        Direction::Down => Direction::Left,
        Direction::Up => Direction:: Right,
        Direction::Right => Direction::Down,
        Direction::Left => Direction::Up
    }
}




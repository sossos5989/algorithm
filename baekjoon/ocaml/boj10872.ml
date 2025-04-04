let _ =
  Printf.printf "%d" (
    let rec factorial n =
      match n with
      | 0 -> 1
      | t -> t * factorial (t-1)
    in factorial (Scanf.scanf "%d" (fun x -> x)))

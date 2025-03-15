let a = Scanf.fscanf stdin "%d" (fun n -> n) in
for i = 1 to 9 do
  Printf.printf "%d * %d = %d\n" a i (a*i)
done
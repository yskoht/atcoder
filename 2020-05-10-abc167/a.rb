 s = gets.chomp
 t = gets.chomp

 if s == t[0..-2] && s.size == t.size - 1
  puts 'Yes'
 else
  puts 'No'
 end


s = gets.chomp.split('')
t = gets.chomp.split('')

cnt = 0
s.zip(t) do |a, b|
  cnt += 1 if a != b
end

puts cnt
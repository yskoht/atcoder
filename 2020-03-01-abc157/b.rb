a1 = gets.chomp.split.map(&:to_i)
a2 = gets.chomp.split.map(&:to_i)
a3 = gets.chomp.split.map(&:to_i)
as = [a1, a2, a3]
n = gets.to_i
n.times do
  b = gets.to_i
  3.times do |i|
    3.times do |j|
      as[i][j] = 'x' if as[i][j] == b
    end
  end
end

if (as[0][0] == 'x' && as[0][1] == 'x' && as[0][2] == 'x') ||
   (as[1][0] == 'x' && as[1][1] == 'x' && as[1][2] == 'x') ||
   (as[2][0] == 'x' && as[2][1] == 'x' && as[2][2] == 'x') ||
   (as[0][0] == 'x' && as[1][0] == 'x' && as[2][0] == 'x') ||
   (as[0][1] == 'x' && as[1][1] == 'x' && as[2][1] == 'x') ||
   (as[0][2] == 'x' && as[1][2] == 'x' && as[2][2] == 'x') ||
   (as[0][0] == 'x' && as[1][1] == 'x' && as[2][2] == 'x') ||
   (as[2][0] == 'x' && as[1][1] == 'x' && as[0][2] == 'x')
  puts 'Yes'
else
  puts 'No'
end
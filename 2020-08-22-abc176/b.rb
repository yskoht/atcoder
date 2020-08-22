n = gets.chomp.split('').map(&:to_i)

s = 0
n.each do |x|
  s += x
  s %= 9
end

if s % 9 == 0
  puts 'Yes'
else
  puts 'No'
end

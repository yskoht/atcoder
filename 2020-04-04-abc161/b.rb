n, m = gets.chomp.split.map(&:to_i)
a = gets.chomp.split.map(&:to_i)

x = a.inject(:+)
y = x.to_f / (4.0 * m)

if a.select { |k| k >= y }.size >= m
  puts 'Yes'
else
  puts 'No'
end

n = gets.chomp.to_i
as = gets.chomp.split.map(&:to_i)

f = as.all? { |a| (a % 2 == 1) || (a % 2 == 0 && (a % 3 == 0 || a % 5 == 0)) }

puts f ? 'APPROVED' : 'DENIED'

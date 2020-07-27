n = gets.to_i
a = gets.chomp.split.map(&:to_i)

dp = Array.new(n)
dp[0] = 1000

1.upto(n-1) do |i|
  m = 0
  0.upto(i-1) do |j|
    t = dp[j] / a[j]
    k = dp[j] - a[j] * t
    k += a[i] * t
    m = [m, k].max
  end
  dp[i] = [dp[i-1], m].max
end

puts dp[n-1]

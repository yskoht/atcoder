s = gets.chomp
K = gets.chomp.to_i

N = s.to_s.size

dp = Array.new(105) { Array.new(4) { Array.new(2, 0) } }

dp[0][0][0] = 1

(0...N).each do |i|
  (0..K).each do |j|
    (0..1).each do |k|
      nd = s[i].to_i
      (0..9).each do |d|
        ni = i + 1
        nj = d == 0 ? j : j + 1
        nk = k == 0 && nd == d ? 0 : 1

        next if nj > K
        next if k == 0 && nd < d

        dp[ni][nj][nk] += dp[i][j][k]
      end
    end
  end
end

puts dp[N][K][0] + dp[N][K][1]
